uses math;
var
  s:ansistring;
  n,ans:longint;
  i:longint;
begin
  readln(n);
  ans:=0;

  for i:=1 to n do
    begin
      readln(s);
      if s[2]='+' then inc(ans)
      else dec(ans);
    end;
  writeln(ans);
end.