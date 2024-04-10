uses math;
var
  a:array[1..10000]of longint;
  n,ans,fula:longint;
  i,j:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);

  fula:=1;
  for i:=1 to n do
    begin
      ans:=1;
      for j:=i+1 to n do
        if a[j]>a[j-1] then break
        else inc(ans);
      for j:=i-1 downto 1 do
        if a[j]>a[j+1] then break
        else inc(ans);
      fula:=max(fula,ans);
    end;
  writeln(fula);
end.