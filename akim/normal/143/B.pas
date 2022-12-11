var s:string;
    toch,i,cher:longint;
    logm:boolean;
begin
 readln(s);logm:=false;
 if s[1]='-'then begin delete(s,1,1);logm:=true;end;
 toch:=pos('.',s);if toch=0 then begin insert('.00',s,length(s)+1);toch:=length(s)+1;end;
 if (toch-1)mod 3=2 then cher:=2;
 if (toch-1)mod 3=1 then cher:=1;
 if (toch-1)mod 3=0 then cher:=3;
 i:=cher+1;
 while s[i]<>'.' do
 begin
  insert(',',s,i);
  i:=i+4;
 end;
 toch:=i;
 delete(s,toch+3,length(s)-toch-2);
 if toch+2<>length(s) then insert('0',s,length(s)+1);
 if logm then write('($') else write('$');
 write(s);
 if logm then write(')');
end.