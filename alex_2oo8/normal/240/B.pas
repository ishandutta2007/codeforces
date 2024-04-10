program problem2;
uses math;

const inf = trunc( 1.0e+9 );

var n, a, b, i, j, k, ad, bd, ans: longInt;
    h, s: array[0..200] of longWord;
    dp: array[ 0..200, 0..40000, 0..1 ] of longWord;
    f: text;

begin
  fillDWord( dp, sizeOf(dp) div sizeOf(dp[0][0][0]), inf );

  assign( f, 'input.txt' );
  reset( f );

  readln( f, n );
  readln( f, a, b );
  s[0] := 0;
  h[0] := 0;
  for i := 1 to n do
  begin
    read( f, h[i] );
    s[i] := s[i-1] + h[i];
  end;

  close( f );

  dp[0][a][0] := 0;
  dp[0][a][1] := 0;
  for i := 0 to (n-1) do
    for j := max( 0, (a-s[i]) ) to a do
    begin
      ad := j;
      bd := b - ( s[i] - (a-j) );

      if ( ad >= h[i+1] ) then
      begin
        dp[i+1][ j - h[i+1] ][0] := min( dp[i+1][ j - h[i+1] ][0], ( dp[i][j][1] + min( h[i], h[i+1] ) ) );
        dp[i+1][ j - h[i+1] ][0] := min( dp[i+1][ j - h[i+1] ][0], dp[i][j][0] );
      end;

      if ( bd >= h[i+1] ) then
      begin
        dp[i+1][j][1] := min( dp[i+1][j][1], ( dp[i][j][0] + min( h[i], h[i+1] ) ) );
        dp[i+1][j][1] := min( dp[i+1][j][1], dp[i][j][1] );
      end;
    end;

  ans := inf;
  for i := 0 to a do
    ans := min( ans, min( dp[n][i][0], dp[n][i][1] ) );


  assign( f, 'output.txt' );
  rewrite( f );

  if ( ans = inf ) then
    writeln( f, '-1' )
  else
    writeln( f, ans );

  close( f );
end.