program problem2;
const d = 1000000007;

function max( a, b: word ): word;
begin
  if ( a > b ) then
    max := a
  else
    max := b;
end;

var n, m, k, i, j: longWord;
    pt: array[ 0..1000, -1..1001 ] of qWord;
    ans: qWord;

begin
  readln( n, m, k );

  if ( ( n - 1 ) < ( 2 * k ) ) or ( ( m - 1 ) < ( 2 * k ) ) then
  begin
    writeln( '0' );
    halt;
  end;

  pt[0][-1] := 0;
  pt[0][0] := 1;
  pt[0][1] := 0;

  for i := 1 to max( n, m ) do
  begin
    pt[i][-1] := 0;
    for j := 0 to i do
      pt[i][j] := ( pt[i-1][j-1] + pt[i-1][j] ) mod d;
    pt[i][i+1] := 0;
  end;

  ans := ( pt[n-1][2*k] * pt[m-1][2*k] ) mod d;

  writeln( ans );
end.