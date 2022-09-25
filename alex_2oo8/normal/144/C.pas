program problem3;

var str, p, substr: ansistring;
    p_cnt, cnt: array['?'..'z'] of longWord;
    i, first: longWord;
    chr: char;
    ok: boolean;
    ans: qWord;

begin
  readln( str );
  readln( p );

  for chr := 'a' to 'z' do
  begin
    p_cnt[chr] := 0;
    cnt[chr] := 0;
  end;
  cnt['?'] := 0;

  if ( length( p ) > length( str ) ) then
  begin
    writeln( '0' );
    halt;
  end;

  for i := 1 to length( p ) do
    inc( p_cnt[ p[i] ] );

  substr := copy( str, 1, length( p ) );

  for i := 1 to length( substr ) do
    inc( cnt[ substr[i] ] );

  i := 1;
  first := length( substr );
  for i := length( p ) to length( str ) do
  begin
    dec( cnt[ substr[first] ] );
    substr[first] := str[i];
    inc( cnt[ substr[first] ] );
    inc( first );
    if ( first > length( substr ) ) then
      first := 1;

    ok := true;
    for chr := 'a' to 'z' do
      if ( cnt[chr] > p_cnt[chr] ) then
      begin
        ok := false;
        break;
      end;

    if ok then
      inc( ans );
  end;

  writeln( ans );
end.