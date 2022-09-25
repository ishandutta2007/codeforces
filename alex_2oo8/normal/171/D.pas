program problem4;

var a: byte;

begin
  readln( a );
  if ( a = 2 ) then
    writeln( 3 )
  else if ( a = 4 ) or ( a = 1 ) then
    writeln( 2 )
  else if ( a = 3 ) or ( a = 5 ) then
    writeln( 1 );
end.