uses math;
const
	maxn=200000;
type
	ll=longint;
	bo=boolean;
	rec=record
		v,head,next:ll;
	end;	
	arr=array[0..maxn] of ll;
	arr1=array[0..2*maxn] of rec;
var
	n,m,k,ans,tot,cnt,t:ll;
	kd,f,num,tmp,hash:arr;
	a:arr1;
function get(x:ll):ll;
begin
	if f[x]=x then exit(x);
	f[x]:=get(f[x]);
	exit(f[x]);
end;	
procedure init;
var
	i,x,y:ll;
begin
	readln(n,m,k);
	for i:=1 to n do
	begin
		read(kd[i]);
		f[i]:=i;
	end;	
	for i:=1 to m do
	begin
		readln(x,y);
		if get(x)<>get(y) then
			f[get(x)]:=get(y);
	end;
end;	
procedure adde(x,y:ll);
begin
	inc(cnt);
	a[cnt].v:=y;
	a[cnt].next:=a[x].head;
	a[x].head:=cnt;	
end;
procedure process;
var
	i,j,u,v:ll;
begin
	for i:=1 to n do
	begin
		u:=get(i);
		adde(u,i);
		inc(num[u]);
	end;	
	for u:=1 to n do
	if num[u]<>0 then
	begin
		tot:=0;
		i:=a[u].head;
		while i<>0 do
		begin
			v:=a[i].v;
			inc(hash[kd[v]]);
			tot:=max(tot,hash[kd[v]]);
			i:=a[i].next;
		end;
		inc(ans,num[u]-tot);
		i:=a[u].head;
		while i<>0 do
		begin
			v:=a[i].v;
			hash[kd[v]]:=0;
			i:=a[i].next;
		end; 
	end;
end;
procedure print;
begin
	writeln(ans);
end;	
begin
	init;
	process;
	print;
end.