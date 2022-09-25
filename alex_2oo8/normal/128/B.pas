program problem4;
var s: array[1..100000] of char;
    groups: array[ 'a'..'z' ] of longWord;
    k, i: longWord;
    s_length: qWord;
    starts: array[ 0..1, 0..100000 ] of longWord;
    chr: char;
    currIndex, lastIndex: byte;
    str: string[1];

begin
  s_length := 0;

  read( str );
  while ( str <> '' ) do
  begin
    inc( s_length );
    s[ s_length ] := str[1];
    read( str );
  end;
  readln;

  readln( k );

  if k > ( ( ( 1 + s_length ) * s_length ) div 2 ) then
  begin
    writeln( 'No such line.' );
    halt;
  end;

  for chr := 'a' to 'z' do
    groups[chr] := 0;

  for i := 1 to s_length do
    groups[ s[i] ] := groups[ s[i] ] + ( s_length - i + 1 );

  chr := 'a';
  while ( k > groups[chr] ) do
  begin
    k := k - groups[chr];
    inc( chr );
  end;
  write( chr );

  for i := 1 to s_length do
    if ( s[i] = chr ) then
    begin
      inc( starts[0][0] );
      starts[0][ starts[0][0] ] := i;
    end;

  currIndex := 1;
  lastIndex := 0;

  while ( k > starts[lastIndex][0] ) do
  begin
    k := k - starts[ lastIndex ][0];

    for chr := 'a' to 'z' do
      groups[chr] := 0;
    for i := 1 to starts[ lastIndex ][0] do
      if ( starts[ lastIndex ][i] < s_length ) then
        groups[ s[ starts[ lastIndex ][i] + 1 ] ] := groups[ s[ starts[ lastIndex ][i] + 1 ] ] + ( s_length - starts[ lastIndex ][i] );

    chr := 'a';
    while ( k > groups[chr] ) do
    begin
      k := k - groups[chr];
      inc( chr );
    end;
    write( chr );

    starts[ currIndex ][0] := 0;
    for i := 1 to starts[ lastIndex ][0] do
      if ( starts[ lastIndex ][i] < s_length ) and ( s[ starts[ lastIndex ][i] + 1 ] = chr ) then
      begin
        inc( starts[ currIndex ][0] );
        starts[ currIndex ][ starts[ currIndex ][0] ] := ( starts[ lastIndex ][i] + 1 );
      end;

    currIndex := 1 - currIndex;
    lastIndex := 1 - lastIndex;
  end;
end.