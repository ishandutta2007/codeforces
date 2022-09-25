program problem1;

var n, i, cnt, k: longWord;
    arr: array[ 1..20 ] of char;
    chr: string[1];

begin
  readln( n );

  cnt := 0;
  read( chr );
  while ( chr <> '' ) do
  begin
    inc( cnt );
    arr[cnt] := chr[1];
    read( chr );
  end;
  readln;

  for i := 2 to n do
  begin
    k := 0;
    read( chr );
    while( chr <> '' ) and ( chr[1] = arr[ k + 1 ] ) and ( k < cnt ) do
    begin
      inc( k );
      read( chr );
    end;
    readln;

    if ( k < cnt ) then
      cnt := k;

  end;

  writeln( cnt );
end.