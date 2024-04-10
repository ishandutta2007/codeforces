program problem1;

var n, k, i, cnt, ak, a: byte;

begin
  readln( n, k );
  cnt := 0;
  for i := 1 to n do
  begin
    read( a );
    if ( i = k ) then
      ak := a;
    if ( a > 0 ) and ( ( i <= k ) or ( a = ak ) ) then
      inc( cnt )
    else if ( a = 0 ) or ( ( i > k ) and ( a < ak ) ) then
      break;
  end;

  writeln( cnt );
end.