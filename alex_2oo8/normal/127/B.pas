program problem2;

var n, i, a, ans: byte;
    cnt: array[1..100] of byte;

begin
  readln( n );
  for i := 1 to 100 do
    cnt[i] := 0;

  for i := 1 to n do
  begin
    read( a );
    if ( cnt[a] = 0 ) then
      inc( cnt[a] )
    else
    begin
      dec( cnt[a] );
      inc( ans );
    end;
  end;

  writeln( ans div 2 );
end.