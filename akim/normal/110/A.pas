var s:string;
    i,o:longint;
begin
 readln(s);
 for i:=1 to length(s) do
  if (s[i]='4')or(s[i]='7') then inc(o);
 if (o=4)or(o=7)then writeln('YES') else writeln('NO');
end.