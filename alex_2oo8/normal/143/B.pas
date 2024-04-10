program problem2;

var chr: string[1];
    sign: boolean;
    number: array[0..100] of byte;
    i: byte;

begin
  number[0] := 0;

  read( chr );
  if ( chr[1] = '-' ) then
  begin
    sign := true;
    read( chr );
  end
  else
    sign := false;

  while ( chr <> '' ) and ( chr[1] in ['0'..'9'] ) do
  begin
    inc( number[0] );
    number[ number[0] ] := ord( chr[1] ) - ord( '0' );
    read( chr );
  end;

  if sign then
    write( '(' );
  write( '$' );
  for i := 1 to number[0] do
  begin
    if ( i <> 1 ) and ( ( ( number[0] - i + 1 ) mod 3 ) = 0 ) then
      write( ',' );
    write( number[i] );
  end;
  write( '.' );
  if ( chr = '.' ) then
    read( chr );
  i := 0;
  while ( chr <> '' ) and ( i < 2 ) do
  begin
    write( chr );
    read( chr );
    inc( i );
  end;
  while ( i < 2 ) do
  begin
    write( '0' );
    inc( i );
  end;
  if sign then
    write( ')' );
end.