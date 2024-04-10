program problem1;

var q, q1: qWord;
    i: longWord;
    d: array[0..2] of longWord;

begin
  readln( q1 );
  q := q1;
  d[0] := 0;

  if ( q1 > 3 ) then
  for i := 2 to ( trunc( sqrt( q1 ) ) + 1 ) do
  begin
    while ( ( q mod i ) = 0 ) do
    begin
      inc( d[0] );
      d[ d[0] ] := i;
      if ( d[0] = 2 ) then
        break;
      q := q div i;
    end;
    if ( d[0] = 2 ) then
      break;
  end;

  q := d[1];
  q := q * d[2];

  if ( d[0] = 0 ) then
  begin
    writeln( '1' );
    writeln( '0' );
  end
  else if ( d[0] = 1 ) or ( ( q ) = q1 ) then
    writeln( '2' )
  else
  begin
    writeln( '1' );
    writeln( q );
  end;
end.