var
 i,n:longint;
 s:ansistring;
begin
 readln(n);
 for i:=1 to n do
 begin
  readln(s);
  if length(s)<=10 then begin writeln(s); continue; end;
  writeln(s[1],length(s)-2,s[length(s)]); 
 end;
end.