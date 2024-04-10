program problem1;
type tArr = array[1..12] of byte;

procedure sort( var arr: tArr );
var i, j, temp: byte;
begin
  for i := 1 to 12 do
  begin
    for j := ( i + 1 ) to 12 do
    begin
      if ( arr[i] < arr[j] ) then
      begin
        temp := arr[i];
        arr[i] := arr[j];
        arr[j] := temp;
      end;
    end;
  end;
end;

var k, cnt, sum, i: byte;
    a: tArr;

begin
  sum := 0;
  cnt := 0;

  readln( k );
  for i := 1 to 12 do
    read( a[i] );

  sort( a );

  while ( sum < k ) and ( cnt < 12 ) do
  begin
    inc( cnt );
    sum := sum + a[ cnt ];
  end;

  if ( sum < k ) then
    writeln( '-1' )
  else
    writeln( cnt );
end.