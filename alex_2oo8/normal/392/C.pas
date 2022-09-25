program problem3;

const   md =    1000000007;

type    tMatrix =   array[ 0..82, 0..82 ] of qWord;

var m: longInt;
    matrix: array[ 0..64 ] of tMatrix;

procedure multiply( var res: tMatrix; const p, q: tMatrix );
var i, j, k: longInt;
begin
    for i := 0 to m do
        for j := 0 to m do
        begin
            res[i][j] := 0;
            for k := 0 to m do
			begin
                res[i][j] := ( res[i][j] + p[i][k] * q[k][j] );
				
				if ( res[i][j] >= md ) and ( k and 3 = 0 ) then
					res[i][j] := res[i][j] mod md;
			end;
			
			res[i][j] := res[i][j] mod md;
        end;
end;

var n: int64;
    i, j, k, x, ans: longInt;
    c: array[ 0..100, 0..100 ] of int64;
    pow2: array[ 0..100 ] of int64;
    ansMatrix, newMatrix: tMatrix;

begin
    fillchar( matrix, sizeOf(matrix), 0 );

    c[0][0] := 1;
    for i := 1 to 100 do
    begin
        c[i][0] := 1;
        for j := 1 to i do
            c[i][j] := ( c[i - 1][j - 1] + c[i - 1][j] ) mod md;
    end;
    
    pow2[0] := 1;
    for i := 1 to 100 do
        pow2[i] := ( 2 * pow2[i - 1] ) mod md;

    readln( n, k );
    
    if ( n = 1 ) then
    begin
        writeln( 1 );
        halt;
    end
    else if ( n = 2 ) then
    begin
        writeln( ( pow2[k + 1] + 1 ) mod md );
        halt;
    end;
    
    for i := 0 to k do
        matrix[0][i][i + k + 1] := 1;
    
    for i := k + 1 to 2 * k + 1 do
    begin
        x := i - k - 1;
        for j := 0 to x do
            matrix[0][i][j + k + 1] := c[x][j];
            
        for j := 0 to x do
            matrix[0][i][j] := ( c[x][j] * pow2[x - j] ) mod md;
    end;
    
    matrix[0][2 * k + 2][2 * k + 2] := 1;
    matrix[0][2 * k + 2][2 * k + 1] := 1;
    
    m := 2 * k + 2; 
    for i := 1 to 56 do
        multiply( matrix[i], matrix[i - 1], matrix[i - 1] );
    
    dec( n, 2 );
    ansMatrix := matrix[0];
    for i := 56 downto 0 do
        if ( n >= int64(1) shl i ) then
        begin
            multiply( newMatrix, ansMatrix, matrix[i] );
            
            ansMatrix := newMatrix;
        
            dec( n, int64(1) shl i );
        end;
    
    ans := ansMatrix[2 * k + 2][2 * k + 2];
    for i := 0 to k do
        ans := ( ans + ansMatrix[2 * k + 2][i] ) mod md;
        
    for i := k + 1 to 2 * k + 1 do
        ans := ( ans + pow2[i - k] * ansMatrix[2 * k + 2][i] ) mod md;
        
    writeln( ans );
end.