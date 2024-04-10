program problem1;

var w: longWord;

begin
  readln( w );
  if ( (w mod 2) = 0 ) and ( w > 2 ) then
    writeln( 'YES' )
  else
    writeln( 'NO' );
end.