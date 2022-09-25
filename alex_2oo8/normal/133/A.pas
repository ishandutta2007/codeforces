program problem1;

var chr: string[1];

begin
  read( chr );
  while ( chr <> '' ) and ( chr[1] <> 'H' ) and ( chr[1] <> 'Q' ) and ( chr[1] <> '9' ) do
    read( chr );

  if ( chr <> '' ) then
    writeln( 'YES' )
  else
    writeln( 'NO' );
end.