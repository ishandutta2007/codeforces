program problem2;

var n, i, ans, l, r, sum, k, res: longWord;
    a: qWord;

begin
  readln( n, k );

  ans := n;
  l := 1;
  r := n;

  while ( r - l ) > 1 do
  begin
    res := ( l + r ) div 2;
    sum := res;
    a := k;
    while ( res >= a ) and ( sum < n ) do
    begin
      sum := sum + ( res div a );
      a := a * k;
    end;
    if ( sum >= n ) then
    begin
      r := res;
      ans := res;
    end
    else
      l := res;
  end;

  writeln( ans );
end.