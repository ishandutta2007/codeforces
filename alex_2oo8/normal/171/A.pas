program problem1;

var a, i: longWord;
    b: qWord;
    chr: string[1];
    arr: array[1..10] of byte;

begin
  i := 0;
  b := 1;

  read( a );

  read( chr );
  while ( chr <> '' ) do
  begin
    if ( chr[1] in ['0'..'9'] ) then
    begin
      inc( i );
      arr[i] := ord( chr[1] ) - ord( '0' );
      b := b * 10;
    end;
    read( chr );
  end;
  b := b div 10;

  for i := i downTo 1 do
  begin
    a := a + ( arr[i] * b );
    b := b div 10;
  end;

  writeln( a );
end.