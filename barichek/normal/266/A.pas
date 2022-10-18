uses math;
var
  s:string;
  ans:longint;
  i:longint;
begin
  readln(ans);
  ans:=0;
  readln(s);
  for i:=2 to length(s) do
    if s[i]=s[i-1] then inc(ans);
  writeln(ans);
end.