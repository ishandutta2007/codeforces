program problem2;

function removeSpaces( var str: ansistring ): ansistring;
var res: ansistring;
    i: longWord;
begin
  res := '';
  for i := 1 to length( str ) do
    if ( str[i] <> ' ' ) then
      res := res + str[i];

  removeSpaces := res;
end;

var str, last_str: ansistring;
    i: longWord;
    last_empty: boolean;

begin
  last_str := '';
  last_empty := true;

  while not eof do
  begin
    readln( str );
    if ( str = '' ) then
      last_empty := false
    else
    begin
      i := 1;
      while ( i < length( str ) ) and ( str[i] = ' ' ) do
        inc( i );
      if ( str[i] = '#' ) then
      begin
        if not last_empty then
        begin
          writeln( last_str );
          last_str := '';
          last_empty := true;
        end;
        writeln( str );
      end
      else
      begin
        last_str := last_str + removeSpaces( str );
        last_empty := false;
      end;
    end;
  end;
  if not last_empty then
    writeln( last_str );

end.