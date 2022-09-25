program problem1;

var n, ur, ul, dr, dl, uldr, i: longWord;
    ans: qWord;
    str: string;

begin
  ur := 0;
  ul := 0;
  dr := 0;
  dl := 0;
  uldr := 0;

  readln( n );
  for i := 1 to n do
  begin
    readln( str );
    if ( str = 'UR' ) then
      inc( ur )
    else if ( str = 'UL' ) then
      inc( ul )
    else if ( str = 'DR' ) then
      inc( dr )
    else if ( str = 'DL' ) then
      inc( dl )
    else
      inc( uldr );
  end;

  ans := qWord( 1 + ur + dl + uldr ) * qWord( 1 + ul + dr + uldr );
  writeln( ans );
end.