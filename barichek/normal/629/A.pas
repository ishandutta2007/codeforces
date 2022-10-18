uses math;
var
  a:array[1..100,1..100]of char;
  n,ans:longint;
  i,j,k:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to n do
        read(a[i,j]);
      readln;
    end;

  for k:=1 to n do
    for i:=1 to n do
      for j:=i+1 to n do
        if (a[i,k]=a[j,k]) and (a[i,k]<>'.') then inc(ans);

  for k:=1 to n do
    for i:=1 to n do
      for j:=i+1 to n do
        if (a[k,i]=a[k,j]) and (a[k,i]<>'.') then inc(ans);

  writeln(ans)
end.