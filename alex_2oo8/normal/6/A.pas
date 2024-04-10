program problem1;
uses math;

var arr: array[1..4] of longWord;
    ans, i, j, k, m: longWord;

begin
  ans := 0;

  readln( arr[1], arr[2], arr[3], arr[4] );

  for i := 1 to 2 do
    for j := (i+1) to 3 do
      for k := (j+1) to 4 do
      begin
        m := max( arr[i], max( arr[j], arr[k] ) );
        if ( (arr[i]+arr[j]+arr[k]-m) > m ) then
          ans := 2
        else if ( (arr[i]+arr[j]+arr[k]-m) = m ) then
          ans := max( ans, 1 );
      end;

  if ( ans = 0 ) then
    writeln( 'IMPOSSIBLE' )
  else if ( ans = 1 ) then
    writeln( 'SEGMENT' )
  else
    writeln( 'TRIANGLE' );
end.