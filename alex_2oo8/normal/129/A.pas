program problem1;

var n, a: byte;
    i: longWord;
    arr: array[ 0..1 ] of byte;

begin
  arr[0] := 0;
  arr[1] := 0;

  readln( n );
  for i := 1 to n do
  begin
    read( a );
    inc( arr[ a mod 2 ] );
  end;

  if ( arr[1] mod 2 ) = 0 then
    writeln( arr[0] )
  else
    writeln( arr[1] );
end.