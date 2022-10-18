uses math;
var
  s:ansistring;
  dop,ans:int64;
  i:longint;
begin
  readln(s);
  for i:=1 to length(s) do
    if (s[i]='0') or (s[i]='4') or (s[i]='8') then inc(ans);

  for i:=2 to length(s) do
    begin
      val(copy(s,i-1,2),dop);
      if dop mod 4=0 then inc(ans,i-1);
    end;

  writeln(ans)
end.