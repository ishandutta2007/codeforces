uses math;
var
  a:array[1..10000]of longint;
  n,m,d,ts,ans:longint;
  i,j:longint;
begin
  read(n,d);
  ans:=0;
  for i:=1 to n do
    begin
      read(m);
      for j:=1 to m do
        begin
          read(ts);
          if d>ts then begin inc(ans); a[ans]:=i; break; end;
        end;
      for j:=1 to m-j do
        read(m);
    end;
  writeln(ans);
  for i:=1 to ans do
    write(a[i],' ');
end.