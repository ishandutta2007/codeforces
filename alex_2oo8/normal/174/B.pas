program problem2;

var str: ansistring;
    lastStr: string[15];
    i, cnt: longWord;
    a: array[1..150000] of string[15];

begin
  lastStr := '';
  cnt := 0;

  readln( str );
  for i := 1 to length( str ) do
  begin
    if ( str[i] = '.' ) then
    begin
      if ( length( lastStr ) < 2 ) and ( ( cnt > 0 ) or ( lastStr = '' ) ) then
      begin
        writeln( 'NO' );
        halt;
      end;
      inc( cnt );
      a[ cnt ] := lastStr;
      lastStr := '';
    end
    else
    begin
      if ( length( lastStr ) = 11 ) then
      begin
        writeln( 'NO' );
        halt;
      end;
      lastStr := lastStr + str[i];
    end;
  end;

  if ( lastStr = '' ) or ( length( a[1] ) > 8 ) or ( length( lastStr ) > 3 ) or ( cnt = 0 ) then
  begin
    writeln( 'NO' );
    halt;
  end;

  inc( cnt );
  a[ cnt ] := lastStr;

  writeln( 'YES' );
  write( a[1] );

  for i := 2 to ( cnt - 1 ) do
  begin
    if ( length( a[i] ) > 3 ) then
    begin
      writeln( '.', copy( a[i], 1, 3 ) );
      write( copy( a[i], 4, ( length( a[i] ) - 3 ) ) );
    end
    else
    begin
      writeln( '.', copy( a[i], 1, 1 ) );
      write( copy( a[i], 2, ( length( a[i] ) - 1 ) ) );
    end;
  end;
  writeln( '.', a[cnt] );
end.