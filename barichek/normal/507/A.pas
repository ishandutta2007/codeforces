uses math;
var
  a,b:array[1..99999]of longint;
  n,t,mini,ans:longint;
  i:longint;
begin
  read(n,t);
  ans:=0;
  for i:=1 to n do
    read(a[i]);

  repeat
    mini:=a[1];
    for i:=1 to n do
      mini:=min(mini,a[i]);
    for i:=1 to n do
      if a[i]=mini then
        begin
          inc(ans);
          b[ans]:=i;
          a[i]:=99999;
          break;
        end;
    dec(t,mini);
  until (t<0) or (ans=n);

  if t<0 then
    begin
      writeln(ans-1);
      for i:=1 to ans-1 do
        write(b[i],' ');
    end
  else
    begin
      writeln(n);
      for i:=1 to n do
        write(b[i],' ');
    end;
end.