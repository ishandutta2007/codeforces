program problem1;

var t: array['A'..'Z'] of integer;
    chr: string[1];
    c: char;
    i: longWord;

begin
  for c := 'A' to 'Z' do
    t[c] := 0;

  for i := 1 to 2 do
  begin
    read( chr );
    while ( chr <> '' ) do
    begin
      dec( t[ chr[1] ] );
      read( chr );
    end;
    readln;
  end;
  read( chr );
  while ( chr <> '' ) do
  begin
    inc( t[ chr[1] ] );
    read( chr );
  end;

  for c := 'A' to 'Z' do
  begin
    if ( t[c] <> 0 ) then
    begin
      writeln( 'NO' );
      halt;
    end;
  end;

  writeln( 'YES' );
end.