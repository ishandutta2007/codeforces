uses math;
var
  s,ans:ansistring;
  i,h:longint;
begin
  read(s);
  h:=0;
  for i:=1 to length(s) do
    if s[i]<>'/' then begin h:=1; break; end;
  if h=0 then begin writeln('/'); halt; end;

  ans:=s[1];
  for i:=2 to length(s) do
    begin
      if s[i]<>'/' then ans:=ans+s[i];
      if (s[i]='/') and (s[i-1]<>'/') then ans:=ans+s[i];
    end;

  for i:=length(ans) downto 1 do
    if ans[i]='/' then ans[i]:=' '
    else break;
  writeln(ans);
end.