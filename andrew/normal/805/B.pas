var
 s:ansistring;
 i,j,n,m,k:longint;
begin
 readln(n);
 if n=1 then begin writeln('a'); halt; end;
 s:='aa';
 for i:=3 to n do if s[i-2]='a' then s:=s+'b'else s:=s+'a';
 writeln(s);
end.