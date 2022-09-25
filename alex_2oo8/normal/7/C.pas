program problem3;

procedure proc( a, b: int64; var x, y, z: int64 );
var x1, y1, z1, x2, y2, z2, t: int64;
begin
  x  := 1; y  := 0; z  := a;
  x1 := 0; y1 := 1; z1 := b;

  while ( z1 <> 0 ) do
  begin
    t := z div z1;

    x2 := x - ( t * x1 );
    y2 := y - ( t * y1 );
    z2 := z - ( t * z1 );

    x  := x1; y  := y1; z :=  z1;
    x1 := x2; y1 := y2; z1 := z2;
  end;
end;

var a, b, c, x, y, z: int64;

begin
  readln( a, b, c );

  if ( a = 0 ) then
  begin
    if ( (c mod b) = 0 ) then
      writeln( '0 ', -(c div b) )
    else
      writeln( '-1' );
    halt;
  end;

  if ( b = 0 ) then
  begin
    if ( (c mod a) = 0 ) then
      writeln( -(c div a), ' 0' )
    else
      writeln( '-1' );
    halt;
  end;

  proc( a, b, x, y, z );
  x := x * (-c div z);
  y := y * (-c div z);

  if ( (-c mod z) <> 0 ) then
    writeln( '-1' )
  else
    writeln( x, ' ', y );
end.