var s:string;
    i,l:longint;
begin
 readln(s);l:=length(s);i:=1;
 while i<=length(s) do
 begin
  if (chr(ord(upcase(s[i]))+32)='a')or(chr(ord(upcase(s[i]))+32)='e')or(chr(ord(upcase(s[i]))+32)='i')or(chr(ord(upcase(s[i]))+32)='o')or(chr(ord(upcase(s[i]))+32)='u')or(chr(ord(upcase(s[i]))+32)='y')then begin delete(s,i,1);dec(i);end else s[i]:=chr(ord(upcase(s[i]))+32);
  inc(i);
 end;
 i:=1;
 while i<=length(s) do
 begin insert('.',s,i);inc(i,2);end;
 writeln(s);
end.