program problem1;
type tArr = array[0..100] of byte;

procedure getMinMaxIndexes( arr: tArr; var min, max: byte; n: byte );
var i: byte;
begin
  min := 1;
  max := 1;

  for i := 1 to n do
  begin
    if ( arr[i] > arr[max] ) then
      max := i;
    if ( arr[i] <= arr[min] ) then
      min := i;
  end;
end;

var n, i, min, max: byte;
    a: tArr;

begin
  readln( n );
  for i := 1 to n do
  begin
    read( a[i] );
  end;

  getMinMaxIndexes( a, min, max, n );

  if ( max > min ) then
    writeln( ( max - 1 ) + ( n - min ) - 1 )
  else
    writeln( ( max - 1 ) + ( n - min ) );
end.