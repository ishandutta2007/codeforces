program problem1;

var str: string;
    cnt, sum: longWord;

begin
  cnt := 0;
  sum := 0;

  readln( str );
  while ( str <> '' ) do
  begin
    if ( str[1] = '+' ) then
      inc( cnt )
    else if ( str[1] = '-' ) then
      dec( cnt )
    else
      inc( sum, ( length(str) - pos(':', str) ) * cnt );

    readln( str );
  end;

  writeln( sum );
end.