program problem5;

var n, i, j, pCnt, x: longInt;
    lp: array[ 1..10000000 ] of longInt;
    p: array[ 1..1000000 ] of longInt;
    pow: array[ 1..1000000 ] of qWord;
    a: array[ 1..10000000 ] of qWord;
    l, r, c, cnt, nb, ans: qWord;

begin
    pCnt := 0;
    for i := 2 to 10000000 do
    begin
        if ( lp[i] = 0 ) then
        begin
            inc( pCnt );
            p[pCnt] := i;
            lp[i] := pCnt;
        end;
        
        j := 1;
        while ( j <= pCnt ) and ( j <= lp[i] ) and ( p[j] <= 10000000 div i ) do
        begin
            lp[ i * p[j] ] := j;
            
            inc( j );
        end;
    end;

    readln( n );
    for i := 1 to n do
    begin
        read( j );
        inc( a[j], 1 );
    end;
    
    for i := 10000000 downTo 2 do
        inc( a[i-1], a[i] );
        
    j := pCnt + 1;
    for i := 10000000 downTo 2 do
        if ( p[ lp[i] ] = i ) then
            pow[ lp[i] ] := a[i]
        else
        begin
            inc( a[ p[ lp[i] ] ], a[i] );
            inc( a[ i div p[ lp[i] ] ], a[i] );
        end;

    ans := 1;
    for i := 1 to pCnt do
    begin
        nb := ans;
        cnt := 0;
        while ( nb > 0 ) and ( cnt < pow[i] ) do
        begin
            inc( cnt, nb div p[i] );
            nb := nb div p[i];
        end;
        
        if ( cnt < pow[i] ) then
        begin
            l := ans + 1;
            r := 10000000000000;
            while ( l < r ) and ( r > ans ) do
            begin
                c := (l+r) div 2;
                
                nb := c;
                cnt := 0;
                while ( nb > 0 ) and ( cnt < pow[i] ) do
                begin
                    inc( cnt, nb div p[i] );
                    nb := nb div p[i];
                end;
                
                if ( cnt < pow[i] ) then
                    l := c + 1
                else
                    r := c;
            end;
            
            ans := l;
        end;
    end;
    
    writeln( ans );
end.