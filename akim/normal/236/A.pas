var a:array['a'..'z']of boolean;
    s:string;
    q,i:longint;
begin
 readln(s);
 for i:=1 to length(s) do
  if not(a[s[i]]) then begin inc(q);a[s[i]]:=true;end;
 if q mod 2=1 then writeln('IGNORE HIM!') else writeln('CHAT WITH HER!');
end.