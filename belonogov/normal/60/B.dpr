{$O-} {$R+}
var
  a: array[0..11, 0..11, 0..11] of longint;
  use: array[0..11, 0..11, 0..11] of boolean;
  sum, i, i1, i2, n, m, k, x, y: longint;
  s: string;

procedure dfs(k1, x, y: longint);


begin
  inc(sum);
  use[k1, x, y] := true;
  if (a[k1 - 1, x, y] = 1) and (k1 > 1) and (not use[k1 - 1 , x, y]) then dfs(k1 - 1, x, y);
  if (a[k1 + 1, x, y] = 1) and (k1 < k) and (not use[k1 + 1, x, y]) then dfs(k1 + 1, x, y);

  if (a[k1, x - 1, y] = 1) and (x > 1) and (not use[k1, x - 1, y]) then dfs(k1, x - 1, y);
  if (a[k1, x + 1, y] = 1) and (x < n) and (not use[k1, x + 1, y]) then dfs(k1, x + 1, y);

  if (a[k1, x, y - 1] = 1) and (y > 1) and (not use[k1, x, y - 1]) then dfs(k1, x, y - 1);
  if (a[k1, x, y + 1] = 1) and (y < m) and (not use[k1, x, y + 1]) then dfs(k1, x, y + 1);

end;

begin
   readln(k, n, m);

  readln;
  for i := 1 to k do
  begin
    for i1 := 1 to n do
    begin
      readln(s);
      for i2 := 1 to m do
      begin
        if s[i2] = '.' then a[i, i1, i2] := 1;
        if s[i2] = '#' then a[i, i1, i2] := 0;
      end;
    end;
    readln;
  end;
  read(x, y);

  sum := 0;
  dfs(1, x , y);


  writeln(sum);


end.