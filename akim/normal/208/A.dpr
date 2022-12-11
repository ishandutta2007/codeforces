var s:string;log:boolean;
begin
 readln(s);insert('WUB',s,length(s)+1);
 while (length(s)>=3)and(s[1]='W')and(s[2]='U')and(s[3]='B') do
 begin
  delete(s,1,3);
 end;
 while s<>'' do
 begin
  if log then write(' ',copy(s,1,pos('WUB',s)-1)) else begin log:=true;write(copy(s,1,pos('WUB',s)-1));end;
  delete(s,1,pos('WUB',s)-1);
  while (length(s)>=3)and(s[1]='W')and(s[2]='U')and(s[3]='B') do
  begin
   delete(s,1,3);
  end;
 end;
end.