program problem3;

var n, i, h: longWord;
    arr: array[0..100000] of longWord;
    str, ans: ansistring;

begin
  ans := '';

  readln( n );
  readln( str );

  h := 0;
  arr[0] := 0;
  i := 1;

  while ( i <= length(str) ) do
  begin
    if ( arr[h] > 0 ) then
      ans := ans + ',';
    if ( str[i] = 'p' ) then
    begin
      inc( arr[h] );
      inc( h );
      arr[h] := 0;
      inc( i, 5 );
      ans := ans + 'pair<';
    end
    else
    begin
      inc( arr[h] );
      ans := ans + 'int';
      while ( arr[h] = 2 ) do
      begin
        ans := ans + '>';
        if ( h = 0 ) then
        begin
          writeln( 'Error occurred' );
          halt;
        end;
        dec( h );
      end;
      inc( i, 4 );
    end;
  end;

  if ( h <> 0 ) or ( arr[h] > 1 ) then
  begin
    writeln( 'Error occurred' );
    halt;
  end;

  writeln( ans );
end.