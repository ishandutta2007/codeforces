uses math;
var
  a:array[0..100000]of longint;
  n:longint;
  i,j:longint;
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
  a[0]:=0;
  a[n+1]:=a[n]+2;
  for i:=1 to n+1 do
    if a[i]-a[i-1]>1 then begin writeln(a[i-1]+1); halt; end;
end.