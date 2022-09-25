program problem4;
uses math;

var n, i, j, k, ans1, ans2: longWord;
    str: ansistring;

begin
  readln( n );
  readln( str );

  ans1 := 0;
  ans2 := 0;
  for i := 1 to n do
  begin
    if ( ( (i mod 2) = 1 ) and ( str[i] = '1' ) ) or ( ( (i mod 2) = 0 ) and ( str[i] = '0' ) ) then
      inc( ans1 )
    else
      inc( ans2 );
  end;

  writeln( min( ans1, ans2 ) );
end.