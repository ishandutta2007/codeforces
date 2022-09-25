program problem4;

var s, t: ansistring;
    pref, suff: array[0..200001] of longInt;
    cnt: array[ 'a'..'z', 0..200000 ] of longWord;
    n, m, i, j, l, r: longInt;
    chr: char;

begin
  readln( s );
  readln( t );

  n := length( s );
  m := length( t );

  pref[0] := 0;
  for i := 1 to n do
  begin
    pref[i] := pref[i-1];
    if ( pref[i] < m ) and ( s[i] = t[ pref[i] + 1 ] ) then
      inc( pref[i] );
  end;

  suff[n+1] := 0;
  for i := n downTo 1 do
  begin
    suff[i] := suff[i+1];
    if ( suff[i] < m ) and ( s[i] = t[ m - suff[i] ] ) then
      inc( suff[i] );
  end;

  for chr := 'a' to 'z' do
  begin
    cnt[chr][0] := 0;
    for i := 1 to m do
    begin
      cnt[chr][i] := cnt[chr][i-1];
      if ( t[i] = chr ) then
        inc( cnt[chr][i] );
    end;
  end;

  for i := 1 to n do
  begin
    if ( ( pref[i-1] + suff[i+1] + 1 ) < m ) or ( ( ( pref[i-1] + suff[i+1] + 1 ) = m ) and ( s[i] <> t[ pref[i-1] + 1 ] ) ) then
    begin
      writeln( 'No' );
      halt;
    end
    else
    begin
      r := pref[i-1] + 1;
      l := m - suff[i+1];

      if ( r > m ) then
        r := m;
      if ( l < 1 ) then
        l := 1;

      if ( ( cnt[ s[i] ][r] - cnt[ s[i] ][l-1] ) = 0 ) then
      begin
        writeln( 'No' );
        halt;
      end;
    end;
  end;

  writeln( 'Yes' );
end.