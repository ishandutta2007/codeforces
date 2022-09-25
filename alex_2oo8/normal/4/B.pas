program problem2;
uses math;

var d, sumTime, sumMin, sumMax, i, k: longWord;
    arr: array[ 1..30, 0..1 ] of longWord;

begin
  readln( d, sumTime );

  sumMin := 0;
  sumMax := 0;

  for i := 1 to d do
  begin
    readln( arr[i][0], arr[i][1] );
    inc( sumMin, arr[i][0] );
    inc( sumMax, arr[i][1] );
  end;

  if ( sumTime > sumMax ) or ( sumTime < sumMin ) then
  begin
    writeln( 'NO' );
    halt;
  end;

  writeln( 'YES' );
  sumTime := sumTime - sumMin;

  for i := 1 to d do
  begin
    k := min( (arr[i][1] - arr[i][0]), sumTime );
    write( (arr[i][0] + k), ' ' );
    sumTime := sumTime - k;
  end;
end.