program problem1;
type tArr = array[0..200000] of longWord;

var i, sum: longWord;
    a, avg: tArr;

begin
  avg[0] := 0;
  sum := 0;

  readln( a[0] );
  for i := 1 to a[0] do
  begin
    read( a[i] );
    sum := sum + a[i];
  end;

  for i := 1 to a[0] do
  begin
    if ( a[i] = ( ( sum - a[i] ) / ( a[0] - 1 ) ) ) then
    begin
      inc( avg[0] );
      avg[ avg[0] ] := i;
    end;
  end;

  writeln( avg[0] );
  for i := 1 to avg[0] do
    write( avg[i], ' ' );
end.