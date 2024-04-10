program problem2;

var str: ansistring;
    arr: array[1..1000] of ansistring;
    cnt, i, j, max, kl, kr: longWord;

begin
  cnt := 0;
  max := 0;

  while ( not EOF ) do
  begin
    readln( str );
    inc( cnt );
    arr[cnt] := str;

    if ( length(str) > max ) then
      max := length(str);
  end;

  for i := 1 to (max+2) do
    write( '*' );
  writeln;

  kl := 1;
  kr := 0;
  for i := 1 to cnt do
  begin
    write( '*' );
    for j := 1 to ( ( max - length(arr[i]) + kr ) div 2 ) do
      write( ' ' );
    write( arr[i] );
    for j := 1 to ( ( max - length(arr[i]) + kl ) div 2 ) do
      write( ' ' );
    writeln( '*' );

    if ( ( max-length(arr[i]) ) mod 2 ) = 1 then
    begin
      kl := 1 - kl;
      kr := 1 - kr;
    end;
  end;

  for i := 1 to (max+2) do
    write( '*' );
  writeln;
end.