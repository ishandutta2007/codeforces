uses math;
var
  s,t:ansistring;
  ans:longint;
  i:longint;
begin
  readln(s);
  readln(t);
  for i:=1 to length(s)-length(t)+1 do
    if copy(s,i,length(t))=t then
      begin
        inc(ans);
        s[i+length(t)-1]:='#';
      end;

  writeln(ans);
end.