program problem2;

var a, n, i, m, u: longWord;
    sq: array[ 0..3162 ] of longWord;
    used: array[ 1..10000000 ] of boolean;
    ans: qWord;

begin
  ans := 0;

  readln( a, n );

  sq[0] := trunc( sqrt( a + n - 1 ) );
  for i := 1 to sq[0] do
    sq[i] := i * i;

  for i := a to ( a + n - 1 ) do
    used[i] := false;

    u := 0;
  for i := sq[0] downTo 1 do
  begin
    if ( a mod sq[i] ) = 0 then
      m := a
    else
      m := a + sq[i] - ( a mod sq[i] );
    while ( m <= ( a + n - 1 ) ) do
    begin
      if not used[m] then
      begin
        used[m] := true;
        ans := ans + ( m div sq[i] );
        inc( u );
      end;
      m := m + sq[i];
    end;

    if ( u = n ) then
      break;
  end;

  writeln( ans );
end.