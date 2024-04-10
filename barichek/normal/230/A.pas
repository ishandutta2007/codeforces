uses math;
var
  a,b:array[1..10000]of longint;
  s,n:longint;
  i,j,t:longint;
begin
  read(s,n);
  for i:=1 to n do
    read(a[i],b[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]<a[j] then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;

          t:=b[i];
          b[i]:=b[j];
          b[j]:=t;
        end;
  for i:=n downto 1 do
    begin
      if s<=a[i] then begin writeln('NO'); halt; end;
      inc(s,b[i]);
    end;
  writeln('YES');
end.