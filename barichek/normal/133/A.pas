uses math;
var
  s:string;
  i:longint;
begin
  read(s);

  for i:=1 to length(s) do
    if (s[i]='H') or (s[i]='Q') or (s[i]='9') then begin writeln('YES'); halt; end;
  writeln('NO');
end.