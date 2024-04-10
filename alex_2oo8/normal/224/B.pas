program problem2;

var n, k, i, cnt, l, ansl, ansr: longWord;
    c, a: array[0..100000] of longWord;

begin
  readln( n, k );

  for i := 1 to 100000 do
    c[i] := 0;

  ansl := 1;
  ansr := n+1;
  l := 1;
  cnt := 0;
  for i := 1 to n do
  begin
    read( a[i] );
    inc( c[ a[i] ] );

    if ( c[ a[i] ] = 1 ) then
      inc( cnt );

    while ( cnt > k ) or ( c[ a[l] ] > 1 ) do
    begin
      dec( c[ a[l] ] );

      if ( c[ a[l] ] = 0 ) then
        dec( cnt );

      inc( l );
    end;

    if ( cnt = k ) and ( (i-l+1) < (ansr-ansl+1) ) then
    begin
      ansl := l;
      ansr := i;
    end;
  end;

  if ( ansr > n ) then
    writeln( '-1 -1' )
  else
    writeln( ansl, ' ', ansr );
end.