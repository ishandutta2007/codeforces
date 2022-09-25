program problem2;
uses math;

const d = 1000000007;

function pow( a, p: qWord ): longWord;
var res: qWord;
begin
  res := 1;
  while ( p > 0 ) do
  begin
    if ( odd(p) ) then
      res := ( res * a ) mod d;

    a := ( a * a ) mod d;
    p := p div 2;
  end;

  pow := res;
end;

var n, k, i, j, l: longWord;
    m: qWord;
    dp: array[ 0..100, 0..10000 ] of longWord;
    c: array[ 0..100, 0..100 ] of longWord;
    cPow: array[ 0..100, 0..1 ] of longWord;

begin
  fillchar( c, sizeOf(c), 0 );
  fillchar( dp, sizeOf(dp), 0 );

  readln( n, m, k );

  c[0][0] := 1;
  for i := 1 to n do
  begin
    c[i][0] := 1;
    for j := 1 to i do
      c[i][j] := ( c[i-1][j-1] + c[i-1][j] ) mod d;
  end;

  for i := 0 to n do
  begin
    cPow[i][0] := pow( c[n][i], ( m div n ) );
    cPow[i][1] := ( qWord( cPow[i][0] ) * c[n][i] ) mod d;
  end;

  dp[0][0] := 1;
  for i := 1 to ( m mod n ) do
    for j := 0 to k do
      for l := 0 to min( n, j ) do
        dp[i][j] := ( dp[i][j] + ( qWord(dp[i-1][j-l]) * cPow[l][1] ) ) mod d;
  for i := ( ( m mod n ) + 1 ) to n do
    for j := 0 to k do
      for l := 0 to min( n, j ) do
        dp[i][j] := ( dp[i][j] + ( qWord(dp[i-1][j-l]) * cPow[l][0] ) ) mod d;


  writeln( dp[n][k] );
end.