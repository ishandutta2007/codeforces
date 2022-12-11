var s:string;
    p:longint;
begin
 readln(s);
 if s[1]='h' then insert('://',s,5) else insert('://',s,4);
 p:=pos('ru',s);
 if (s[1]='f')and(p<=7)or(s[1]='h')and(p<=8) then begin inc(p);while (s[p]<>'r')or(s[p+1]<>'u')do inc(p);end;
 insert('.',s,p);
 insert('/',s,p+3);
 if s[length(s)]='/' then delete(s,length(s),1);
 writeln(s);
end.