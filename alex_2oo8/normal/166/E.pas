program problem3;
const divender = 1000000007;

var n, i, currIndex, lastIndex: longWord;
    dp: array[ 0..1, 'A'..'D' ] of qWord;

begin
  readln( n );

  dp[0]['A'] := 0;
  dp[0]['B'] := 0;
  dp[0]['C'] := 0;
  dp[0]['D'] := 1;

  for i := 1 to n do
  begin
    currIndex := i mod 2;
    lastIndex := ( i + 1 ) mod 2;
    dp[ currIndex ]['A'] := ( dp[ lastIndex ]['B'] + dp[ lastIndex ]['C'] + dp[ lastIndex ]['D'] ) mod divender;
    dp[ currIndex ]['B'] := ( dp[ lastIndex ]['A'] + dp[ lastIndex ]['C'] + dp[ lastIndex ]['D'] ) mod divender;
    dp[ currIndex ]['C'] := ( dp[ lastIndex ]['A'] + dp[ lastIndex ]['B'] + dp[ lastIndex ]['D'] ) mod divender;
    dp[ currIndex ]['D'] := ( dp[ lastIndex ]['A'] + dp[ lastIndex ]['B'] + dp[ lastIndex ]['C'] ) mod divender;
  end;

  writeln( dp[ n mod 2 ]['D'] );
end.