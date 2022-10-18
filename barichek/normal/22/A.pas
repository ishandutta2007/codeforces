uses math;
var
  a:array[1..10000]of longint;
  n:int64;
  i,j,h:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);

  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]<a[j] then
        begin
          a[i]:=a[i]+a[j];
          a[j]:=a[i]-a[j];
          a[i]:=a[i]-a[j];
        end;

  for i:=1 to n div 2 do
    begin
      a[i]:=a[i]+a[n-i+1];
      a[n-i+1]:=a[i]-a[n-i+1];
      a[i]:=a[i]-a[n-i+1];
    end;

  for i:=2 to n do
    if a[i]<>a[i-1] then begin writeln(a[i]); halt; end;

  writeln('NO');
end.