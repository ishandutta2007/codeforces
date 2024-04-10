program problem3;
const d = 1000000007;

function binpow( a, b: qWord ):qWord;
var c: qWord;
begin
    if ( b = 0 ) then
        exit( 1 )
    else if ( b = 1 ) then
        exit( a );

    c := binpow( a, ( b div 2 ) );
    if ( ( b mod 2 ) = 0 ) then
        binpow := ( c * c ) mod d
    else
        binpow := ( c * c * a ) mod d;
end;

var n, k, ans: qWord;

begin
    readln( n );
    k := binpow( 2, n );
    ans := ( ( k * ( k + 1 ) ) div 2 ) mod d;
    
    writeln( ans );
end.