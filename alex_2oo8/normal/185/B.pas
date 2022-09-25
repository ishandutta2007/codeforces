program problem4;

var s, a, b, c: longWord;
    x, y, z: real;

begin
  readln( s, a, b, c );

  if ( a = 0 ) and ( b = 0 ) and ( c = 0 ) then
  begin
    writeln( '0 0 0' );
    halt;
  end;

  x := ( s * a ) / ( a + b + c );
  y := ( s * b ) / ( a + b + c );
  z := ( s * c ) / ( a + b + c );

  writeln( x:0:10, ' ', y:0:10, ' ', z:0:10 );
end.