uses math;
var
  a:array[1..10000000]of longint;
  s,my,ans:ansistring;
  n:longint;
  i,j:longint;
begin
  readln(s);
  readln(ans);
  for i:=1 to length(s) do
    a[i]:=ord(s[i])-48;

  n:=length(s);
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

  if a[1]=0 then
    for i:=2 to length(s) do
      if a[i]<>0 then
        begin
          a[1]:=a[1]+a[i];
          a[i]:=a[1]-a[i];
          a[1]:=a[1]-a[i];
          break;
        end;
  for i:=1 to length(s) do
    my:=my+chr(a[i]+48);

  if my=ans then writeln('OK')
  else writeln('WRONG_ANSWER');
end.